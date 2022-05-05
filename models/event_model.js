const db = require('../database');

const event = {
    getAllEvents: function(cardSerial, callback){
        return db.query('SELECT * FROM events WHERE cardSerial=? ORDER BY datetime DESC', [cardSerial], callback);
    },

    getTenEvents: function(cardSerial, callback) {
        return db.query('SELECT * FROM events where cardSerial=? ORDER BY datetime DESC LIMIT 10', [cardSerial], callback);
    },

    addEvent: function(event, callback){
        return db.query('INSERT INTO events (cardSerial, dateTime, eventType, amount) values (?, ?, ?, ?)', [event.cardSerial, event.dateTime, event.eventType, event.amount], callback);
    }
};
module.exports = event;