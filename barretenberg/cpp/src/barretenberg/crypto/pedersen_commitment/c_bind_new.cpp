#include "../pedersen_hash/pedersen.hpp"
#include "barretenberg/common/serialize.hpp"
#include "c_bind.hpp"
#include "pedersen.hpp"

extern "C" {

using namespace barretenberg;

WASM_EXPORT void pedersen___init() {}

WASM_EXPORT void pedersen___commit(fr::vec_in_buf inputs_buffer, fr::out_buf output)
{
    std::vector<grumpkin::fq> to_compress;
    read(inputs_buffer, to_compress);
    grumpkin::g1::affine_element pedersen_hash = crypto::pedersen_commitment::commit_native(to_compress);

    serialize::write(output, pedersen_hash);
}

WASM_EXPORT void pedersen___buffer_to_field(uint8_t const* data, fr::out_buf r)
{
    std::vector<uint8_t> to_compress;
    read(data, to_compress);
    auto output = crypto::pedersen_hash::hash_buffer(to_compress);
    write(r, output);
}
}