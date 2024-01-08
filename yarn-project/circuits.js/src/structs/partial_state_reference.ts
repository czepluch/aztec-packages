import { BufferReader } from '@aztec/foundation/serialize';

import { serializeToBuffer } from '../utils/serialize.js';
import { AppendOnlyTreeSnapshot } from './rollup/append_only_tree_snapshot.js';

/**
 * Stores snapshots of trees which are commonly needed by base or merge rollup circuits.
 */
export class PartialStateReference {
  constructor(
    /** Snapshot of the note hash tree. */
    public readonly noteHashTree: AppendOnlyTreeSnapshot,
    /** Snapshot of the nullifier tree. */
    public readonly nullifierTree: AppendOnlyTreeSnapshot,
    /** Snapshot of the contract tree. */
    public readonly contractTree: AppendOnlyTreeSnapshot,
    /** Snapshot of the public data tree. */
    public readonly publicDataTree: AppendOnlyTreeSnapshot,
  ) {}

  static fromBuffer(buffer: Buffer | BufferReader): PartialStateReference {
    const reader = BufferReader.asReader(buffer);
    return new PartialStateReference(
      reader.readObject(AppendOnlyTreeSnapshot),
      reader.readObject(AppendOnlyTreeSnapshot),
      reader.readObject(AppendOnlyTreeSnapshot),
      reader.readObject(AppendOnlyTreeSnapshot),
    );
  }

  toBuffer() {
    return serializeToBuffer(this.noteHashTree, this.nullifierTree, this.contractTree, this.publicDataTree);
  }
}
