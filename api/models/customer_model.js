const db = require('../database');

const customer = {
    getCustomer: function(customerID, callback){
        return db.query('SELECT * FROM customers WHERE customerID=?', [customerID], callback);
    },
    getCustomerIDByAccountID: function(accountID, callback){
        return db.query('SELECT customerID FROM customeraccount WHERE accountID=?',  [accountID], callback);
    }
};
module.exports = customer;