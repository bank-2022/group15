const db = require('../database');

const account = {
    getAccountInfoByCardSerial: function(cardSerial, callback){
        return db.query('SELECT * FROM accounts INNER JOIN cards ON accounts.accountID = cards.accountID WHERE cardSerial=?', cardSerial, callback);
    },
    withdraw: function(accountID, withdrawalAmount, callback){
        return db.query('UPDATE accounts SET balance=balance-? where accountID=?', [withdrawalAmount, accountID], callback);
    }
};

module.exports = account;
