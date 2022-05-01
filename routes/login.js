const express = require('express');
const router = express.Router();
const bcrypt = require('bcrypt');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.username && request.body.password){
      const username = request.body.username;
      const password = request.body.password;
        login.checkPassword(username, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              if(dbResult.lockedAt != NULL) {
                response.send("card locked");
              } 
              else{
                if(bcrypt.compareSync(password, dbResult[0].pin)) {
                  console.log("success");
                  const token = generateAccessToken({username: username})
                  response.send(token);
              }
              else {
                  console.log("wrong password");
                  response.send("false wrong password");
                }			
              }
            }
            else{
              console.log("user does not exists");
              response.send("false user");
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send("user/pass missing");
    }
  }
);

router.put('/lock', function(request, response) {
    login.lockCard(request.body, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(request.body);
      }
    })
  });

router.put('/unlock', function(request, response) {
  login.unlockCard(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  })
});

function generateAccessToken(username) {
    dotenv.config();
    return jwt.sign(username, process.env.MY_TOKEN, {expiresIn: '1800s'});
  }
  

module.exports=router;