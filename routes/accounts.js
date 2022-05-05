const express = require('express');
const router = express.Router();
const account = require('../models/account_model');

// KT-0002 #2
// Hakee kaikki tilin tiedot kortin numerolla
router.get('/:cardSerial', function(request, response) {
    account.getAccountInfoByCardSerial(request.params.cardSerial, function(err, dbResult) {
        if(err){
            response.json(err);
        }
        else {
            response.json(dbResult);
        }
    });
});


router.put('/:cardSerial/credit/:withdrawalAmount', function(request, response) {
    account.getAccountInfoByCardSerial(request.params.cardSerial, function(err, dbResult) {
        if(err){
            response.json(err);
        }
        else {
            if(parseInt(request.params.withdrawalAmount) > parseInt(dbResult[0].balance)){
                response.json("Not enough balance");
            }
            else {
                account.credit(dbResult[0].accountID, request.params.withdrawalAmount, function(err, dbResult) {
                    if(err){
                        response.json(err);
                    }
                    else {
                        response.send('Withdrawn successfully');
                    }
                });
            }
        }
    });
});

//KT-0004 #3
// Tarkistaa onko annettu määrä pienempi kuin tilin kate
// Jos on, päivittää tietokantaan vähennyksen
router.put('/:cardSerial/withdraw/:withdrawalAmount', function(request, response) {
    account.getAccountInfoByCardSerial(request.params.cardSerial, function(err, dbResult) {
        if(err){
            response.json(err);
        }
        else {
            if(parseInt(request.params.withdrawalAmount) > parseInt(dbResult[0].balance)){
                response.json("Not enough balance");
            }
            else {
                account.withdraw(dbResult[0].accountID, request.params.withdrawalAmount, function(err, dbResult) {
                    if(err){
                        response.json(err);
                    }
                    else {
                        response.send('Withdrawn successfully');
                    }
                });
            }
        }
    });
});


router.put('/:cardSerial/deposit/:depositAmount', function(request, response) {
    account.getAccountInfoByCardSerial(request.params.cardSerial, function(err, dbResult) {
        if(err){
            response.json(err);
        }
        else {
            account.deposit(dbResult[0].accountID, request.params.depositAmount, function(err, dbResult) {
                if(err){
                    response.json(err);
                }
                else {
                    response.send('Deposited successfully');
                }
            });
            
        }
    });
});

module.exports = router;