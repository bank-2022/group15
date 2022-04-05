const db = require('../database');

const event = {
    getAllEvents: function(accountID, callback){
        return db.query('SELECT * FROM events WHERE accountID=?', [accountID], callback);
    }
};
module.exports = event;