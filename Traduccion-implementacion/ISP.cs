#include <iostream>

// UI Interfaces
class DepositUI {
public:
    virtual void RequestDepositAmount() = 0;
    virtual ~DepositUI() = default;
};

class WithdrawalUI {
public:
    virtual void RequestWithdrawalAmount() = 0;
    virtual ~WithdrawalUI() = default;
};

class TransferUI {
public:
    virtual void RequestTransferAmount() = 0;
    virtual ~TransferUI() = default;
};

// Ttransaccion Base Class
class Transaction {
public:
    virtual void Execute() = 0;
    virtual ~Transaction() = default;
};

// transaccion implementacion
class DepositTransaction : public Transaction {
public:
    DepositTransaction(DepositUI& ui) : itsDepositUI(ui) {}
    void Execute() override {
        itsDepositUI.RequestDepositAmount();
        
    }

private:
    DepositUI& itsDepositUI;
};

class WithdrawalTransaction : public Transaction {
public:
    WithdrawalTransaction(WithdrawalUI& ui) : itsWithdrawalUI(ui) {}
    void Execute() override {
        itsWithdrawalUI.RequestWithdrawalAmount();

    }

private:
    WithdrawalUI& itsWithdrawalUI;
};

class TransferTransaction : public Transaction {
public:
    TransferTransaction(TransferUI& ui) : itsTransferUI(ui) {}
    void Execute() override {
        itsTransferUI.RequestTransferAmount();
    
    }

private:
    TransferUI& itsTransferUI;
};

// Combina UI Interface
class UI : public DepositUI, public WithdrawalUI, public TransferUI {
public:
    void RequestDepositAmount() override {
        std::cout << "Enter deposit amount: ";
    }

    void RequestWithdrawalAmount() override {
        std::cout << "Enter withdrawal amount: ";
    }

    void RequestTransferAmount() override {
        std::cout << "Enter transfer amount: ";
    }
};

int main() {
    UI ui;  

    DepositTransaction depositTransaction(ui);
    depositTransaction.Execute();

    WithdrawalTransaction withdrawalTransaction(ui);
    withdrawalTransaction.Execute();

    TransferTransaction transferTransaction(ui);
    transferTransaction.Execute();

    return 0;
}
