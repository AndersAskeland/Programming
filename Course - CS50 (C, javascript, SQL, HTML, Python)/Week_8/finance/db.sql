/* For SQLLITE3 */

CREATE TABLE 'stocks' ('stockID' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
                                    'stockSymbol' TEXT NOT NULL,
                                    'name' TEXT NOT NULL,
                                    'buyPrice' INTEGER NOT NULL,
                                    'sellPrice' INTEGER,
                                    'totalPrice' INTEGER,
                                    'shares' INTEGER NOT NULL,
                                    'id' INTEGER NOT NULL, 
                                    FOREIGN KEY(id) REFERENCES users(id)); 

CREATE TABLE 'history' ('sellID' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
                                    'stockSymbol' TEXT NOT NULL,
                                    'name' TEXT NOT NULL,
                                    'shares' TEXT NOT NULL,
                                    'price' INTEGER NOT NULL,
                                    'timestamp' NOT NULL DEFAULT CURRENT_TIMESTAMP,
                                    'id' INTEGER NOT NULL,
                                    FOREIGN KEY(id) REFERENCES users(id));
                    db.execute("UPDATE stocks SET buyPrice = ((((buyPrice * shares) + (:buyPrice * :shares))/ (shares + :shares)) / 2), shares = (shares + :shares) WHERE stockSymbol = :stockSymbol AND id = :id", buyPrice=stock["price"], stockSymbol=stock["symbol"], shares=request.form.get("shares"), id=session["user_id"])
