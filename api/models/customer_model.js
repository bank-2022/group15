const db = require('../database');

const customer = {
    //Hae customerinfo customerID:llä
    getCustomerByCustomerID: function(customerID, callback){
        return db.query('SELECT * FROM customers WHERE customerID=?', [customerID], callback);
    },
    
    //Hae customerinfo tilinumerolla (jos tilinumero customeraccount -taulussa)
    getCustomerByAccountNumber:  function(accountNumber, callback){
        return db.query('select * from customers INNER JOIN customeraccount ON customers.customerID = customeraccount.customerID where accountNumber=?', accountNumber, callback);
    },

    //Jos ylempi ei toimi, hae customerinfo accountIDllä(joka pitää varmaan myös poistaa koska tilinumero on unique)
    getCustomerByAccountID:  function(accountID, callback){
        return db.query('select * from customers INNER JOIN customeraccount ON customers.customerID = customeraccount.customerID where accountID=?', accountID, callback);
    }
};
module.exports = customer;