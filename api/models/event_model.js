const db = require('../database');

const event = {
    getAllEvents: function(cardSerial, callback){
        return db.query('SELECT * FROM events WHERE cardSerial=?', [cardSerial], callback);
    },

    getTenEvents: function(cardSerial, callback) {
        return db.query('SELECT * FROM events where cardSerial=? ORDER BY datetime DESC LIMIT 10', [cardSerial], callback);
    }
};
module.exports = event;