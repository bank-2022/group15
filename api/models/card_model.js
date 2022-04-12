const db = require('../database');
const bcrypt = require('bcrypt');
const saltRounds=10;

const card = {
    checkIfCardExists: function(serial, callback){
        return db.query('SELECT * FROM cards WHERE cardSerial=?', [serial], callback);
    },
    getCardPin: function(serial, callback){
        return db.query('SELECT pin FROM cards WHERE cardSerial=?', [serial], callback);
    },
    debugAddCard: function(serial, pin, accountID, callback){
        bcrypt.hash(pin, saltRounds, function(err, hashed_pin){
            if (err) {
                response.json(err);
              } else {
                return db.query('insert into cards (cardSerial, pin, accountID) values(?, ?, ?)', [serial, hashed_pin, accountID], callback);
              }
        }) 
    }
};
module.exports = card;