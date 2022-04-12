const express = require('express');
const router = express.Router();
const card = require('../models/card_model');
const bcrypt = require('bcrypt');

// KT-0001 #4
// Tarkistaa ensin, löytyykö korttia tietokannasta, jos löytyy, vertaa annettua pinniä tietokannan hashiin
router.get('/:cardSerial/:pin', async function(request, response) {
  card.getCardPin(request.params.cardSerial, function(err, dbResult) {
      if(err){
        response.send(err);
      }
      else {
        if(dbResult == ""){
          response.send("Korttia ei löydy");
        }
        else {
          if(bcrypt.compareSync(request.params.pin, dbResult[0].pin)){
            response.send("Oikea pin");
          }
          else {
            response.send("Väärä pin");
          }
        }
      }
  })
});

// Debuggausfunktio kortin lisäämiseen, anna serial (uniikki), pin ja account id
// Huom. POST ja PUT ei toimi selaimessa, käytä testaukseen postmään
router.post('/addCard', function(request, response) {
  card.debugAddCard(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

module.exports = router;
