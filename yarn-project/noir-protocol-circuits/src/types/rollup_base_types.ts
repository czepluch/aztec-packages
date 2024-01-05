/* Autogenerated file, do not edit! */

/* eslint-disable */

export type FixedLengthArray<T, L extends number> = L extends 0 ? never[] : T[] & { length: L };

export type Field = string;
export type u32 = string;

export interface AggregationObject {}

export interface SideEffect {
  value: Field;
  counter: u32;
}

export interface SideEffectLinkedToNoteHash {
  value: Field;
  note_hash: Field;
  counter: u32;
}

export interface AztecAddress {
  inner: Field;
}

export interface CallerContext {
  msg_sender: AztecAddress;
  storage_contract_address: AztecAddress;
}

export interface CallRequest {
  hash: Field;
  caller_contract_address: AztecAddress;
  caller_context: CallerContext;
  start_side_effect_counter: Field;
  end_side_effect_counter: Field;
}

export interface EthAddress {
  inner: Field;
}

export interface NewContractData {
  contract_address: AztecAddress;
  portal_contract_address: EthAddress;
  function_tree_root: Field;
}

export interface FunctionSelector {
  inner: u32;
}

export interface FunctionData {
  selector: FunctionSelector;
  is_internal: boolean;
  is_private: boolean;
  is_constructor: boolean;
}

export interface OptionallyRevealedData {
  call_stack_item_hash: Field;
  function_data: FunctionData;
  vk_hash: Field;
  portal_contract_address: EthAddress;
  pay_fee_from_l1: boolean;
  pay_fee_from_public_l2: boolean;
  called_from_l1: boolean;
  called_from_public_l2: boolean;
}

export interface PublicDataUpdateRequest {
  leaf_slot: Field;
  old_value: Field;
  new_value: Field;
}

export interface PublicDataRead {
  leaf_slot: Field;
  value: Field;
}

export interface CombinedAccumulatedData {
  aggregation_object: AggregationObject;
  read_requests: FixedLengthArray<SideEffect, 128>;
  new_commitments: FixedLengthArray<SideEffect, 64>;
  new_nullifiers: FixedLengthArray<SideEffectLinkedToNoteHash, 64>;
  private_call_stack: FixedLengthArray<CallRequest, 8>;
  public_call_stack: FixedLengthArray<CallRequest, 8>;
  new_l2_to_l1_msgs: FixedLengthArray<Field, 2>;
  encrypted_logs_hash: FixedLengthArray<Field, 2>;
  unencrypted_logs_hash: FixedLengthArray<Field, 2>;
  encrypted_log_preimages_length: Field;
  unencrypted_log_preimages_length: Field;
  new_contracts: FixedLengthArray<NewContractData, 1>;
  optionally_revealed_data: FixedLengthArray<OptionallyRevealedData, 4>;
  public_data_update_requests: FixedLengthArray<PublicDataUpdateRequest, 16>;
  public_data_reads: FixedLengthArray<PublicDataRead, 16>;
}

export interface BlockHeader {
  note_hash_tree_root: Field;
  nullifier_tree_root: Field;
  contract_tree_root: Field;
  l1_to_l2_message_tree_root: Field;
  archive_root: Field;
  public_data_tree_root: Field;
  global_variables_hash: Field;
}

export interface GrumpkinPoint {
  x: Field;
  y: Field;
}

export interface ContractDeploymentData {
  deployer_public_key: GrumpkinPoint;
  constructor_vk_hash: Field;
  function_tree_root: Field;
  contract_address_salt: Field;
  portal_contract_address: EthAddress;
}

export interface TxContext {
  is_fee_payment_tx: boolean;
  is_rebate_payment_tx: boolean;
  is_contract_deployment_tx: boolean;
  contract_deployment_data: ContractDeploymentData;
  chain_id: Field;
  version: Field;
}

export interface CombinedConstantData {
  block_header: BlockHeader;
  tx_context: TxContext;
}

export interface KernelCircuitPublicInputs {
  end: CombinedAccumulatedData;
  constants: CombinedConstantData;
  is_private: boolean;
}

export interface Proof {}

export interface VerificationKey {}

export interface PreviousKernelData {
  public_inputs: KernelCircuitPublicInputs;
  proof: Proof;
  vk: VerificationKey;
  vk_index: u32;
  vk_path: FixedLengthArray<Field, 3>;
}

export interface AppendOnlyTreeSnapshot {
  root: Field;
  next_available_leaf_index: u32;
}

export interface NullifierLeafPreimage {
  nullifier: Field;
  next_nullifier: Field;
  next_index: u32;
}

export interface NullifierMembershipWitness {
  leaf_index: Field;
  sibling_path: FixedLengthArray<Field, 20>;
}

export interface PublicDataTreeLeaf {
  slot: Field;
  value: Field;
}

export interface PublicDataTreeLeafPreimage {
  slot: Field;
  value: Field;
  next_slot: Field;
  next_index: u32;
}

export interface PublicDataMembershipWitness {
  leaf_index: Field;
  sibling_path: FixedLengthArray<Field, 40>;
}

export interface ArchiveRootMembershipWitness {
  leaf_index: Field;
  sibling_path: FixedLengthArray<Field, 16>;
}

export interface GlobalVariables {
  chain_id: Field;
  version: Field;
  block_number: Field;
  timestamp: Field;
}

export interface ConstantRollupData {
  archive_snapshot: AppendOnlyTreeSnapshot;
  private_kernel_vk_tree_root: Field;
  public_kernel_vk_tree_root: Field;
  base_rollup_vk_hash: Field;
  merge_rollup_vk_hash: Field;
  global_variables: GlobalVariables;
}

export interface BaseRollupInputs {
  kernel_data: PreviousKernelData;
  start_note_hash_tree_snapshot: AppendOnlyTreeSnapshot;
  start_nullifier_tree_snapshot: AppendOnlyTreeSnapshot;
  start_contract_tree_snapshot: AppendOnlyTreeSnapshot;
  start_public_data_tree_snapshot: AppendOnlyTreeSnapshot;
  archive_snapshot: AppendOnlyTreeSnapshot;
  sorted_new_nullifiers: FixedLengthArray<Field, 64>;
  sorted_new_nullifiers_indexes: FixedLengthArray<u32, 64>;
  low_nullifier_leaf_preimages: FixedLengthArray<NullifierLeafPreimage, 64>;
  low_nullifier_membership_witness: FixedLengthArray<NullifierMembershipWitness, 64>;
  new_commitments_subtree_sibling_path: FixedLengthArray<Field, 26>;
  new_nullifiers_subtree_sibling_path: FixedLengthArray<Field, 14>;
  public_data_writes_subtree_sibling_path: FixedLengthArray<Field, 36>;
  new_contracts_subtree_sibling_path: FixedLengthArray<Field, 16>;
  sorted_public_data_writes: FixedLengthArray<PublicDataTreeLeaf, 16>;
  sorted_public_data_writes_indexes: FixedLengthArray<u32, 16>;
  low_public_data_writes_preimages: FixedLengthArray<PublicDataTreeLeafPreimage, 16>;
  low_public_data_writes_witnesses: FixedLengthArray<PublicDataMembershipWitness, 16>;
  public_data_reads_preimages: FixedLengthArray<PublicDataTreeLeafPreimage, 16>;
  public_data_reads_witnesses: FixedLengthArray<PublicDataMembershipWitness, 16>;
  archive_root_membership_witness: ArchiveRootMembershipWitness;
  constants: ConstantRollupData;
}

export interface BaseOrMergeRollupPublicInputs {
  rollup_type: u32;
  rollup_subtree_height: Field;
  end_aggregation_object: AggregationObject;
  constants: ConstantRollupData;
  start_note_hash_tree_snapshot: AppendOnlyTreeSnapshot;
  end_note_hash_tree_snapshot: AppendOnlyTreeSnapshot;
  start_nullifier_tree_snapshot: AppendOnlyTreeSnapshot;
  end_nullifier_tree_snapshot: AppendOnlyTreeSnapshot;
  start_contract_tree_snapshot: AppendOnlyTreeSnapshot;
  end_contract_tree_snapshot: AppendOnlyTreeSnapshot;
  start_public_data_tree_snapshot: AppendOnlyTreeSnapshot;
  end_public_data_tree_snapshot: AppendOnlyTreeSnapshot;
  calldata_hash: FixedLengthArray<Field, 2>;
}

export type ReturnType = BaseOrMergeRollupPublicInputs;

export interface InputType {
  inputs: BaseRollupInputs;
}
