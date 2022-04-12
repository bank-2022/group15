const mysql = require('mysql');

/*
// phpmyadmin
const connection = mysql.createPool({
    host: 'sql11.freemysqlhosting.net',
    user: 'sql11483788',
    password: 'RLT81kyjtp',
    database: 'sql11483788'
});
*/

 // localhost
const connection = mysql.createPool({
    host: 'localhost',
    user: 'testiuser',
    password: 'testipass',
    database: 'mydb'
});


module.exports = connection;
