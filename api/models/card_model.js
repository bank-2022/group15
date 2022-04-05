const db = require('../database');

const card = {
    getAccountBySerialPin: function(serial, pin, callback){
        return db.query('SELECT accountID FROM cards WHERE cardSerial=? && pin=?', [serial, pin], callback);
    },
    getCustomerInfoBySerialPin: function(serial, pin, callback){
        return db.query('SELECT accountID FROM cards WHERE cardSerial=? && pin=?', [serial, pin], callback);
    }
};
module.exports = card;