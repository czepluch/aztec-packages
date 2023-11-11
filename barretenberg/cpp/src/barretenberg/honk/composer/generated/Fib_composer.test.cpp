#include "barretenberg/honk/composer/generated/Fib_composer.hpp"
#include "barretenberg/ecc/curves/bn254/fr.hpp"
#include "barretenberg/honk/flavor/generated/Fib_flavor.hpp"
#include "barretenberg/honk/proof_system/generated/Fib_prover.hpp"
#include "barretenberg/honk/proof_system/generated/Fib_verifier.hpp"
#include "barretenberg/honk/sumcheck/sumcheck_round.hpp"
#include "barretenberg/honk/utils/grand_product_delta.hpp"
#include "barretenberg/numeric/uint256/uint256.hpp"
#include "barretenberg/proof_system/plookup_tables/types.hpp"
#include "barretenberg/proof_system/relations/permutation_relation.hpp"
#include "barretenberg/proof_system/relations/relation_parameters.hpp"
#include <cstddef>
#include <cstdint>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace proof_system::honk;

namespace example_relation_honk_composer {

class FibTests : public ::testing::Test {
  protected:
    // TODO(640): The Standard Honk on Grumpkin test suite fails unless the SRS is initialised for every test.
    void SetUp() override { barretenberg::srs::init_crs_factory("../srs_db/ignition"); };
};

namespace {
auto& engine = numeric::random::get_debug_engine();
}

TEST_F(FibTests, powdre2e)
{
    barretenberg::srs::init_crs_factory("../srs_db/ignition");

    auto circuit_builder = proof_system::FibTraceBuilder();
    circuit_builder.build_circuit();

    auto composer = FibComposer();

    circuit_builder.check_circuit();

    auto prover = composer.create_prover(circuit_builder);
    auto proof = prover.construct_proof();
    info(proof);

    auto verifier = composer.create_verifier(circuit_builder);
    bool verified = verifier.verify_proof(proof);
    ASSERT_EQ(verified, true);

    info("We verified a proof!");
}

} // namespace example_relation_honk_composer