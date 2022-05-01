const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin, lockedAt FROM cards WHERE cardSerial = ?',[username], callback); 
    },

  lockCard: function(login, callback) {
    return db.query('UPDATE cards SET lockedAt = ? WHERE cardSerial = ?', [login.lockDateTime, login.cardSerial], callback);
  },
  unlockCard: function(login, callback) {
    return db.query('UPDATE cards SET lockedAt = NULL WHERE cardSerial = ?', [login.cardSerial], callback);
  }
};
          
module.exports = login;