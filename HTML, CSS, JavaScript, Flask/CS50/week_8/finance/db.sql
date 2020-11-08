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
