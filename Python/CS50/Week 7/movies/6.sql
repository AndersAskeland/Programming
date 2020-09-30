-- Determine the average rating of all movies released in 2012.
SELECT avg(rating)
FROM ratings 
LEFT JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;