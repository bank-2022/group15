const express = require('express');
const router = express.Router();
const card = require('../models/card_model');
const customer = require('../models/customer_model');

router.get('/:cardSerial/:pin', function(request, response) {

  card.getAccountBySerialPin(request.params.cardSerial, request.params.pin, function(err, dbResult_Card) {
    if (err) {
      response.json(err);
    } else {
      customer.getCustomerIDByAccountID(dbResult_Card[0].accountID, function(err, dbResult_CustomerAccount) {
        if (err) {
          response.json(err);
        } else {
          customer.getCustomer(dbResult_CustomerAccount[0].customerID, function(err, dbResult_Customer) {
            if (err) {
              response.json(err);
            } else {
              response.json(dbResult_Customer);
            }
          });
        }
      });
    }
  });
});

module.exports = router;
