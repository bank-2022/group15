const db = require('../database');

const customer = {
    getCustomerInfoByCardSerial: function(cardSerial, callback){
        return db.query('select name, address, phoneNumber from customers INNER JOIN customeraccount ON customers.customerID = customeraccount.customerID INNER JOIN cards ON cards.accountID = customeraccount.accountID where cardSerial=?', cardSerial, callback);
    }
};
module.exports = customer;