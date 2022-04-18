const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin FROM cards WHERE cardSerial = ?',[username], callback); 
    }
};
          
module.exports = login;