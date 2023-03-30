#include "index.hpp"
#include "init.hpp"

#include "aztec3/circuits/abis/new_contract_data.hpp"
#include <aztec3/circuits/mock/mock_kernel_circuit.hpp>

#include "barretenberg/proof_system/types/composer_type.hpp"

#include <barretenberg/stdlib/hash/keccak/keccak.hpp>

namespace {
using NT = aztec3::utils::types::NativeTypes;
using AggregationObject = aztec3::utils::types::NativeTypes::AggregationObject;
using aztec3::circuits::abis::PreviousKernelData;
using aztec3::circuits::mock::mock_kernel_circuit;

}  // namespace

namespace aztec3::circuits::kernel::private_kernel::utils {

/**
 * @brief Create a fake verification key
 *
 * @details will not work with real circuits
 *
 * @return std::shared_ptr<NT::VK> fake verification key
 */
std::shared_ptr<NT::VK> fake_vk()
{
    std::map<std::string, NT::bn254_point> commitments;
    commitments["FAKE"] = *new NT::bn254_point(NT::fq(0), NT::fq(0));
    NT::VKData vk_data = { .composer_type = proof_system::ComposerType::TURBO,
                           .circuit_size = 2048,
                           .num_public_inputs = 116,
                           .commitments = commitments,
                           .contains_recursive_proof = false,
                           .recursive_proof_public_input_indices = {} };
    auto env_crs = std::make_unique<proof_system::EnvReferenceStringFactory>();
    return std::make_shared<NT::VK>(std::move(vk_data), env_crs->get_verifier_crs());
}

/**
 * @brief Create a dummy "previous kernel"
 *
 * @details For use in the first iteration of the  kernel circuit
 *
 * @param real_vk_proof should the vk and proof included be real and usable by real circuits?
 * @return PreviousKernelData<NT> the previous kernel data for use in the kernel circuit
 */
PreviousKernelData<NT> dummy_previous_kernel(bool real_vk_proof = false)
{
    PreviousKernelData<NT> const init_previous_kernel{};

    auto crs_factory = std::make_shared<EnvReferenceStringFactory>();
    Composer mock_kernel_composer = Composer(crs_factory);
    auto mock_kernel_public_inputs = mock_kernel_circuit(mock_kernel_composer, init_previous_kernel.public_inputs);

    auto mock_kernel_prover = mock_kernel_composer.create_prover();
    NT::Proof const mock_kernel_proof =
        real_vk_proof ? mock_kernel_prover.construct_proof() : NT::Proof{ .proof_data = std::vector<uint8_t>(64, 0) };

    std::shared_ptr<NT::VK> const mock_kernel_vk =
        real_vk_proof ? mock_kernel_composer.compute_verification_key() : fake_vk();

    PreviousKernelData<NT> previous_kernel = {
        .public_inputs = mock_kernel_public_inputs,
        .proof = mock_kernel_proof,
        .vk = mock_kernel_vk,
    };

    // TODO(rahul) assertions don't work in wasm and it isn't worth updating barratenberg to handle our error code
    // mechanism. Apparently we are getting rid of this function (dummy_previous_kernel()) soon anyway.
    assert(!mock_kernel_composer.failed());

    return previous_kernel;
}

NT::address compute_ethereum_address_from_public_key(const NT::secp256k1_point& public_key)
{
    std::vector<uint8_t> public_key_hash = stdlib::keccak<UltraComposer>::hash_native(public_key.to_buffer());
    std::vector<uint8_t> chopped_public_key_hash(public_key_hash.size(), 0);
    for (size_t i = 12; i < 32; i++) {
        chopped_public_key_hash[i] = public_key_hash[i];
    }
    return NT::fr::serialize_from_buffer(&chopped_public_key_hash[0]);
}

} // namespace aztec3::circuits::kernel::private_kernel::utils
