var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');

var indexRouter = require('./routes/index');
var cardsRouter = require('./routes/cards');
var eventsRouter = require('./routes/events');
var customersRouter = require('./routes/customers');
var accountsRouter = require('./routes/accounts');
var app = express();


app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/cards', cardsRouter);
app.use('/events', eventsRouter);
app.use('/customers', customersRouter);
app.use('/accounts', accountsRouter);

module.exports = app;
