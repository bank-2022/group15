const express = require('express');
const router = express.Router();
const card = require('../models/card_model');
const customer = require('../models/customer_model');
const bcrypt = require('bcrypt');
const res = require('express/lib/response');

//Hae customerinfo tilinumerolla (jos tilinumero customeraccount -taulussa)
router.get('/:accountNumber/', function(request, response) {
    customer.getCustomerByAccountNumber(request.params.accountNumber, function(err, dbResult) {
        if (err) {
            response.json(err);
          } else {
              response.json(dbResult);
          }
    });
});

//Jos ylempi ei toimi, hae customerinfo accountIDllä(joka pitää varmaan myös poistaa koska tilinumero on unique)
router.get('/id/:accountID/', function(request, response) {
    customer.getCustomerByAccountID(request.params.accountID, function(err, dbResult) {
        if (err) {
            response.json(err);
          } else {
              response.json(dbResult);
          }
    });
});


module.exports = router;