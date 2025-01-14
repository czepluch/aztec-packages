/**
 * The `@aztec/accounts/single_key` export provides a testing account contract implementation that uses a single Grumpkin key for both authentication and encryption.
 * It is not recommended to use this account type in production.
 *
 * @packageDocumentation
 */
import { AccountManager, Salt } from '@aztec/aztec.js/account';
import { AccountWallet, getWallet } from '@aztec/aztec.js/wallet';
import { AztecAddress } from '@aztec/circuits.js';
import { CompleteAddress, GrumpkinPrivateKey, PXE } from '@aztec/types';

import { SingleKeyAccountContract } from './account_contract.js';

export { SingleKeyAccountContract };

export { SchnorrSingleKeyAccountContractArtifact as SingleKeyAccountContractArtifact } from './artifact.js';

/**
 * Creates an Account that uses the same Grumpkin key for encryption and authentication.
 * @param pxe - An PXE server instance.
 * @param encryptionAndSigningPrivateKey - Grumpkin key used for note encryption and signing transactions.
 * @param saltOrAddress - Deployment salt or complete address if account contract is already deployed.
 */
export function getSingleKeyAccount(
  pxe: PXE,
  encryptionAndSigningPrivateKey: GrumpkinPrivateKey,
  saltOrAddress?: Salt | CompleteAddress,
): AccountManager {
  return new AccountManager(
    pxe,
    encryptionAndSigningPrivateKey,
    new SingleKeyAccountContract(encryptionAndSigningPrivateKey),
    saltOrAddress,
  );
}

/**
 * Gets a wallet for an already registered account using Schnorr signatures with a single key for encryption and authentication.
 * @param pxe - An PXE server instance.
 * @param address - Address for the account.
 * @param signingPrivateKey - Grumpkin key used for note encryption and signing transactions.
 * @returns A wallet for this account that can be used to interact with a contract instance.
 */
export function getSingleKeyWallet(
  pxe: PXE,
  address: AztecAddress,
  signingKey: GrumpkinPrivateKey,
): Promise<AccountWallet> {
  return getWallet(pxe, address, new SingleKeyAccountContract(signingKey));
}

export { getSingleKeyAccount as getUnsafeSchnorrAccount };
export { getSingleKeyWallet as getUnsafeSchnorrWallet };
