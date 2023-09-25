import { createSandbox } from '@aztec/aztec-sandbox';
import { Contract, Fr, computeMessageSecretHash, createAccount } from '@aztec/aztec.js';
import { TokenContractAbi } from '@aztec/noir-contracts/artifacts';

describe('token', () => {
  // docs:start:setup
  let rpc, stop, owner, recipient, token;
  beforeAll(async () => {
    ({ rpcServer: rpc, stop } = await createSandbox());
    owner = await createAccount(rpc);
    recipient = await createAccount(rpc);

    token = await Contract.deploy(owner, TokenContractAbi, []).send().deployed();
    await token.methods._initialize(owner.getAddress()).send().wait();

    const initialBalance = 20n;
    const secret = Fr.random();
    const secretHash = await computeMessageSecretHash(secret);
    await token.methods.mint_private(initialBalance, secretHash).send().wait();
    await token.methods.redeem_shield(owner.getAddress(), initialBalance, secret).send().wait();
  }, 60_000);

  afterAll(() => stop());
  // docs:end:setup

  // docs:start:test
  it('increases recipient funds on transfer', async () => {
    expect(await token.methods.balance_of_private(recipient.getAddress()).view()).toEqual(0n);
    await token.methods.transfer(owner.getAddress(), recipient.getAddress(), 20n, 0).send().wait();
    expect(await token.methods.balance_of_private(recipient.getAddress()).view()).toEqual(20n);
  });
  // docs:end:test
});
