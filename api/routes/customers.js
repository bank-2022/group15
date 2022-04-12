const express = require('express');
const router = express.Router();
const customer = require('../models/customer_model');


// KT-0001 #6
// KT-0002 #2
// Hakee kaikki asiakkaan tiedot kortin numerolla
router.get('/:cardSerial', function(request, response) {
    customer.getCustomerInfoByCardSerial(request.params.cardSerial, function(err, dbResult) {
        if(err){
            response.json(err);
        }
        else {
            response.json(dbResult);
        }
    });
});

module.exports = router;