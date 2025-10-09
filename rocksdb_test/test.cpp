// 1. Include the DuckDB header
#include "duckdb.hpp"
#include <iostream>

using namespace duckdb;

int main() {
    // 2. Create a database instance. This can be in-memory or file-based.
    // For an in-memory database, use nullptr or an empty string.
    // For a file-based database, pass a path: DuckDB db("my_database.db");
    DuckDB db(nullptr);
    Connection con(db);

    std::cout << "DuckDB Version: " << DuckDB::LibraryVersion() << std::endl;

    // 3. Create a table
    con.Query("CREATE TABLE people (id INTEGER, name VARCHAR);");

    // 4. Insert data into the table
    con.Query("INSERT INTO people VALUES (1, 'Mark'), (2, 'Hannes');");

    // 5. Query the data and get the result set
    auto result = con.Query("SELECT id, name FROM people;");

    // Check if the query was successful
    if (!result->HasError()) {
        std::cout << "Query successful! Fetching results..." << std::endl;
        // 6. Iterate over the results and print them
        for (auto &row : *result) {
            // Get data by column index
            int id = row.GetValue<int32_t>(0);
            std::string name = row.GetValue<std::string>(1);
            std::cout << "ID: " << id << ", Name: " << name << std::endl;
        }
    } else {
        std::cerr << "Query failed with error: " << result->GetError() << std::endl;
    }

    return 0;
}