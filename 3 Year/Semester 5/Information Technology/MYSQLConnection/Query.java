package MYSQLConnection;

public class Query {

    public static class P1 {

        public static final String Q1 = "SELECT COUNT(*) FROM STUDENT;";
        public static final String Q2A = "SELECT AVG(";
        public static final String Q2B =   ")" +
                                        "FROM RESULT R;";
        public static final String Q3 = "SELECT S.NAME, (R.S1 + R.S2 + R.S3)" +
                                        "FROM STUDENT S " +
                                        "JOIN RESULT R " +
                                        "ON S.ROLL = R.SID " +
                                        "ORDER BY 2 DESC " +
                                        "LIMIT 1; ";
        public static final String Q4 = "SELECT COUNT(*)," + 
        		"		CASE " + 
        		"			WHEN MARKS > 224 THEN 1 " + 
        		"			WHEN MARKS < 225 AND MARKS > 149 THEN 2 " + 
        		"			ELSE 3 END AS DIVISION " + 
        		"		FROM ( " + 
        		"			SELECT S1 + S2 + S3 AS MARKS " + 
        		"			FROM RESULT " + 
        		"		) SD " + 
        		"		GROUP BY 2 " + 
        		"		ORDER BY 2; ";
        public static final String Q5 = "WITH AGG AS ( " + 
        		"	SELECT S.NAME AS NAME, " + 
        		"			R.S1 AS S1, " + 
        		"			R.S2 AS S2, " + 
        		"			R.S3 AS S3 " + 
        		"		FROM STUDENT S " + 
        		"		JOIN RESULT R " + 
        		"		ON S.ROLL = R.SID) " + 
        		"		SELECT NAME, CONCAT(MAX(S1), ' in S1') AS HIGHEST_MARKS " + 
        		"			FROM AGG " + 
        		"		UNION " + 
        		"		SELECT NAME, CONCAT(MAX(S2), ' in S2') AS HIGHEST_MARKS " + 
        		"			FROM AGG " + 
        		"		UNION " + 
        		"		SELECT NAME, CONCAT(MAX(S3), ' in S3') AS HIGHEST_MARKS " + 
        		"			FROM AGG;";
        public static final String Q6 = "SELECT S.NAME AS NAME, R.S1 AS SUB1, R.S2 AS SUB2, R.S3 AS SUB3, (R.S1 + R.S2 + R.S3)/3 as AVERAGE_MARKS" + 
        		"	FROM STUDENT S" + 
        		"	JOIN RESULT R" + 
        		"	ON S.ROLL = R.SID;";
        public static final String Q7 = "SELECT NAME, MAXIMUM_MARKS " + 
        		"	FROM " + 
        		"	(SELECT S.NAME AS NAME, (R.S1 + R.S2 + R.S3) AS MAXIMUM_MARKS " + 
        		"	FROM STUDENT S " + 
        		"	JOIN RESULT R " + 
        		"	ON S.ROLL = R.SID " + 
        		"	ORDER BY 2 DESC " + 
        		"	LIMIT 2) SD " + 
        		"	ORDER BY 2 " + 
        		"	LIMIT 1; ";
    }
    public static class P2{
        public static final String Q1 = "{call getRows(?)}";
        public static final String Q2 = "SELECT sub1, sub2, sub3 FROM RESULT WHERE studentID = (SELECT roll FROM student WHERE name = ?);";
    
    }
    

}
