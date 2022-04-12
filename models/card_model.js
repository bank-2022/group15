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
    debugAddCard: function(card, callback){
        bcrypt.hash(card.pin, saltRounds, function(err, hashed_pin){
            if (err) {
                response.json(err);
              } else {
                return db.query('insert into cards (cardSerial, pin, accountID) values(?, ?, ?)', [card.cardSerial, hashed_pin, card.accountID], callback);
              }
        }) 
    }
};
module.exports = card;