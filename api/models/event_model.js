const db = require('../database');

const event = {
    getAllEvents: function(cardSerial, callback){
        return db.query('SELECT * FROM events WHERE cardSerial=?', [cardSerial], callback);
    }
};
module.exports = event;