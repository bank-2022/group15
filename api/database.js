const mysql = require('mysql');
const connection = mysql.createPool({
    host: 'localhost',
    user: 'testiuser',
    password: 'testipass',
    database: 'mydb'
});



module.exports = connection;
