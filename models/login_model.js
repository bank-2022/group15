const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin, lockedTime FROM cards WHERE cardSerial = ?',[username], callback); 
    },

  lockCard: function(login, callback) {
    return db.query('UPDATE cards SET lockedTime = ? WHERE cardSerial = ?', [login.lockDateTime, login.cardSerial], callback);
  },
  unlockCard: function(login, callback) {
    return db.query('UPDATE cards SET lockedTime = NULL WHERE cardSerial = ?', [login.cardSerial], callback);
  }
};
          
module.exports = login;