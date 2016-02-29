SELECT 
  w.Id 
FROM 
  Weather w
WHERE 
  w.Temperature > 
(
SELECT 
  iw.Temperature 
FROM 
  Weather iw 
WHERE 
  iw.Date = date_sub(w.Date, interval 1 day)
);