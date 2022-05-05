const express = require('express');
const router = express.Router();
const event = require('../models/event_model');

// KT-0002 #2
// Hakee viimeisimmät 10 tilitapahtumaa kortin numerolla
router.get('/:cardSerial/last10', function(request, response) {
    event.getTenEvents(request.params.cardSerial, function(err, dbResult_Event) {
        if (err) {
          response.json(err);
        } else {
            response.json(dbResult_Event);
        }
    });
});

// KT-0003 #2
// Hakee kaikki tilitapahtumat kortin numerolla
router.get('/:cardSerial', function(request, response) {
    event.getAllEvents(request.params.cardSerial, function(err, dbResult_Event) {
        if (err) {
          response.json(err);
        } else {
            response.json(dbResult_Event);
        }
    });
});

//luo eventin
router.post('/add/', function(request, response) {
    event.addEvent(request.body, function(err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(request.body);
        }
    });
});

module.exports = router;
