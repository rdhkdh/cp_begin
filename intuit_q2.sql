SELECT 
    sector, 
    CASE
        WHEN SUM(
            CASE
                WHEN capitalization LIKE '%B' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'B', '') AS DECIMAL(20,6)) *1000
                WHEN capitalization LIKE '%M' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'M', '') AS DECIMAL(20,6))
            END
        ) >= 1000 THEN CONCAT(
            ROUND(SUM(
                CASE
                    WHEN capitalization LIKE '%B' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'B', '') AS DECIMAL(20,6)) *1000
                    WHEN capitalization LIKE '%M' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'M', '') AS DECIMAL(20,6))
                END
            )/1000, 2), 'B'
        )
        ELSE CONCAT(
            ROUND(SUM(
                CASE
                    WHEN capitalization LIKE '%B' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'B', '') AS DECIMAL(20,6)) *1000
                    WHEN capitalization LIKE '%M' THEN CAST(REPLACE(REPLACE(capitalization, '$', ''), 'M', '') AS DECIMAL(20,6))
                END
            ), 2), 'M'
        )
    END
    AS total_capitalization
FROM companies
WHERE sector!='n/a' AND capitalization!='n/a'
GROUP BY sector
ORDER BY sector;