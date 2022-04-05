const express = require('express');
const router = express.Router();
const card = require('../models/card_model');
const customer = require('../models/customer_model');
const bcrypt = require('bcrypt');
const res = require('express/lib/response');


//Tarkistaa ensin, löytyykö korttia tietokannasta, jos löytyy, vertaa annettua pinniä tietokannan hashiin
router.get('/:cardSerial/:pin', async function(request, response) {
  card.checkIfCardExistsBySerial(request.params.cardSerial, async function(err, dbResult_Card) {
    if (err) {
      response.json(err);
    } else {
        if(dbResult_Card.cardSerial == ""){
          response.send("Korttia ei löydy");
        }
        else {
          card.checkCardPin(dbResult_Card[0].cardSerial, 
            function(err, dbResult_Pin) {
              if(err){
                response.send(err);
              }
              else {
                let bool = bcrypt.compareSync(request.params.pin, dbResult_Card[0].pin)

                if(bool == true){
                  response.send("Oikea pin");

                  // tässä vaiheessa pitää varmaan päättää että haetaanko tässä kohtaa kaikki käyttäjän infot
                  // qt-olioon (ei turvallista) vai haetaanko joka käyttötapauksessa erikseen tietokannasta jutut
                }
                else {
                  response.send("Väärä pin");
                }
              }
          })
        }
      }
    })
});

// Debuggausfunktio kortin lisäämiseen, anna serial (uniikki), pin ja account id
// Jostain syystä tää toimii postmanilla mutta ei suoraan urlilla
router.post('/addCard/:cardSerial/:pin/:accountID', function(request, response) {
  card.debugAddCard(request.params.cardSerial, request.params.pin, request.params.accountID, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;
