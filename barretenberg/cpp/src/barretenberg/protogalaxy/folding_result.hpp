#pragma once
#include "barretenberg/flavor/flavor.hpp"
#include "barretenberg/relations/relation_parameters.hpp"
#include "barretenberg/sumcheck/instance/prover_instance.hpp"
namespace proof_system::honk {
/**
 * @brief The result of running the Protogalaxy prover containing a new accumulator (relaxed instance) as well as the
 * proof data to instantiate the verifier transcript.
 *
 * @tparam Flavor
 */
template <class Flavor> struct FoldingResult {
  public:
    std::shared_ptr<ProverInstance_<Flavor>> accumulator;
    // TODO(https://github.com/AztecProtocol/barretenberg/issues/656): turn folding data into a struct
    std::vector<uint8_t> folding_data;
};
} // namespace proof_system::honk