const db = require('../database');
const bcrypt = require('bcrypt');
const saltRounds=10;

const card = {
    
    //Tarkistaa serialilla löytyykö korttia tietokannasta
    checkIfCardExistsBySerial: function(serial, callback){
        return db.query('SELECT * FROM cards WHERE cardSerial=?', [serial], callback);
    },
    //Hakee pin-hashin verrattavaksi
    checkCardPin: function(serial, callback){
        return db.query('SELECT pin FROM cards WHERE cardSerial=?', [serial], callback);
    },


    /*
    /* Tämä hakisi kaikki customer-tiedot kortin serialilla ja pinnillä mutta loginin jälkeen
    /* ei ehkä kantsis pyöritellä pinniä.
    /*
    getCustomerInfoBySerialPin: function(serial, pin, callback){
        return db.query('select * from cards INNER JOIN customeraccount ON cards.accountID = customeraccount.accountID INNER JOIN customers ON customeraccount.customerID = customers.customerID where cardSerial=? && pin=?', [serial, pin], callback);
    },
    */


    //Debuggausfunktio kortin lisäämiseen, anna unique serial, pin ja account id
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