WITH SIZE_TILE AS (
SELECT ID, NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC) AS PER FROM ECOLI_DATA
)

SELECT ID, CASE PER
                            WHEN 1 THEN 'CRITICAL'
                            WHEN 2 THEN 'HIGH'
                            WHEN 3 THEN 'MEDIUM'
                            WHEN 4 THEN 'LOW'
                            ELSE 'ERROR'
                            END AS COLONY_NAME
    FROM SIZE_TILE
        ORDER BY ID