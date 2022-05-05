var crypto = require('crypto');
var co = require('co');

function spawnTokenbuf() {
    return function(callback) {
        crypto.randomBytes(64, callback);
    };
}

co(function* () {
    console.log((yield spawnTokenbuf()).toString
    ('base64'));
});