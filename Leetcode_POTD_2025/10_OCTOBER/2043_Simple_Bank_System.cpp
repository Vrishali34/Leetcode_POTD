class Bank {
private:
    std::vector<long long> cosmic_bal;
    bool is_valid_entry(int account, long long amount = 0) {
        if (account < 1 || account > cosmic_bal.size()) return false;
        if (amount == 0) return true;
        return cosmic_bal[account - 1] >= amount;
    }

public:
    Bank(std::vector<long long>& balance) {
        cosmic_bal = balance;
    }
    
    bool transfer(int sender_ac, int receiver_ac, long long quantum) {
        if (!is_valid_entry(sender_ac, quantum) || !is_valid_entry(receiver_ac)) return false;
        cosmic_bal[sender_ac - 1] -= quantum;
        cosmic_bal[receiver_ac - 1] += quantum;
        return true;
    }
    
    bool deposit(int ac_num, long long meteor) {
        if (!is_valid_entry(ac_num)) return false;
        cosmic_bal[ac_num - 1] += meteor;
        return true;
    }
    
    bool withdraw(int ac_num, long long black_hole) {
        if (!is_valid_entry(ac_num, black_hole)) return false;
        cosmic_bal[ac_num - 1] -= black_hole;
        return true;
    }
};
