const express = require('express');
const router = express.Router();
const event = require('../models/event_model');


router.get('/:cardSerial', function(request, response) {
    event.getAllEvents(request.params.cardSerial, function(err, dbResult_Event) {
        if (err) {
          response.json(err);
        } else {
            response.json(dbResult_Event);
        }
    });


});


module.exports = router;
