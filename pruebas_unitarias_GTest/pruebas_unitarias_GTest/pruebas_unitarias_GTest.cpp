// pruebas_unitarias_GTest.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <gtest/gtest.h>


struct BankAccount {
	int	balance = 0;
	BankAccount(){
	}
	explicit BankAccount(const int balance) : balance{balance}{
	}
	void depositar(int monto) { balance += monto; }
	bool withdraw(int amount) {
		if (amount <= balance) {
			balance -= amount;
			return true;
		}
		return false;
	};
};

struct BankAccountTest : testing::Test{
	BankAccount* account;
	BankAccountTest(){
		account = new BankAccount;
	}
	virtual ~BankAccountTest(){
		delete account;
	}
};

TEST_F(BankAccountTest, BankAccountStartsEmpty)
{
	EXPECT_EQ(0, account->balance);
}

TEST_F(BankAccountTest, CanDepositMoney) {
	account->depositar(100);
	EXPECT_EQ(100, account->balance);
}


struct account_state {
	int initial_balance;
	int withdraw_amount;
	int final_balance;
	bool success;
};

struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> {
	WithdrawAccountTest() {
		account->balance = GetParam().initial_balance;
	}
};

TEST_P(WithdrawAccountTest, FinalBalance){
	auto as = GetParam();
	auto success = account->withdraw(as.withdraw_amount);
	EXPECT_EQ(as.final_balance, account->balance);
	EXPECT_EQ(as.success, success);
}

INSTANTIATE_TEST_SUITE_P(Default, WithdrawAccountTest,
	testing::Values(
		account_state{ 100,50,50,true },
		account_state{ 100,200,100,false }
));

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
