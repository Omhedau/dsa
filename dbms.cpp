/* 
What is Data?
Data is a collection of a distinct small unit of information. It can be used in a variety of forms like text, numbers, media, bytes, etc. it can be stored in pieces of paper or electronic memory, etc.

-------------------------------------------------------------------------

what is database?
A database is essentially a structured collection of data stored electronically, designed to manage, organize, and retrieve information efficiently.

--------------------------------------------------------------------------

What is DBMS?
Database Management System (DBMS) is software for storing and retrieving users’ data while considering appropriate security measures. It consists of a group of programs that manipulate the database. The DBMS accepts the request for data from an application and instructs the operating system to provide the specific data. In large systems, a DBMS helps users and other third-party software store and retrieve data.

----------------------------------------------------------------------

why need DBMS?
* Data Integrity and Consistency: It ensures that the data remains accurate and consistent across the database, even when multiple users are accessing it simultaneously.
* Data Security: A DBMS provides robust security features to protect sensitive data, allowing administrators to control access based on user roles.
* Concurrency Control: It manages concurrent data access, ensuring that multiple users can work on the same data without conflicts.
* Scalability and Flexibility: DBMSs are scalable, allowing organizations to handle growing data volumes and adapt databases to evolving business needs.
* Cost-Effectiveness:DBMSs are cost-effective compared to traditional file-based systems. They reduce storage costs by eliminating redundancy and optimizing data storage. They also reduce development costs by providing tools for database design, maintenance, and administration
* Data Abstraction: The DBMS provides a layer of abstraction, allowing users to interact with data through high-level queries without needing to understand the underlying storage details.

-------------------------------------------------------------------------

file system vs dbms

A file system is a method of storing and organizing files on a storage device, like a hard drive, where data is arranged in a hierarchical structure of directories and files. It allows basic operations like creating, reading, updating, and deleting files, but has limited capabilities for managing large amounts of structured data or enforcing data integrity and security.

1. Data Organization:
* File System: Data is stored in files, usually in a hierarchical structure, with limited ability to relate data across files.
* DBMS: Data is organized into tables with relationships between them, enabling more complex querying and analysis.

2. Data Security:
* File System: Security is generally limited to file permissions, and there’s little control over how data is accessed and manipulated.
* DBMS: Provides robust security features, including authentication, authorization, and encryption, ensuring that only authorized users can access or modify the data.

3. Data Integrity and Consistency:
* File System: Lacks mechanisms to enforce data integrity, leading to potential issues with data duplication or inconsistency.
* DBMS: Enforces data integrity through constraints and ACID properties, ensuring that data remains accurate and consistent across transactions.

4. Concurrent Data Access:
* File System: Concurrent access is limited, and there’s a higher risk of data corruption when multiple users access the same file.
* DBMS: Manages concurrent access effectively using locking mechanisms, ensuring data integrity even when multiple users are accessing or modifying data simultaneously.

5. Scalability and Flexibility:
* File System: Limited in scalability; handling large datasets becomes inefficient and difficult.
* DBMS: Scalable and flexible, capable of handling large datasets, and adaptable to changing business requirements.

-----------------------------------------------------------------------

database languages 

DDL (Data Definition Language)
DDL or Data Definition Language actually consists of the SQL commands that can be used to define the database schema. It simply deals with descriptions of the database schema and is used to create and modify the structure of database objects in the database.

ex:- create, drop, alter, truncate, rename

Data Manipulation Language (DML): DML is used to query and modify data within the database. It includes commands like SELECT, INSERT, UPDATE, and DELETE, which allow you to retrieve and manipulate data stored in tables.

Data Control Language (DCL): DCL is concerned with the rights and permissions within the database. It includes commands like GRANT and REVOKE, which are used to control access to data and database objects.

Transaction Control Language (TCL): TCL is used to manage transactions within a database, ensuring data integrity and consistency. Commands like COMMIT, ROLLBACK, and SAVEPOINT are used to control transaction behavior.

------------------------------------------------------------------------

Types of Keys in Relational Model

Super Key
The set of attributes that can uniquely identify a tuple is known as Super Key. A candidate key is a super key but vice versa is not true.

Candidate Key
The minimal set of attributes that can uniquely identify a tuple is known as a candidate key.

primary key
There can be more than one candidate key in relation out of which one can be chosen as the primary key.

Alternate Key
The candidate key other than the primary key is called an alternate key.

A foreign key
is a field (or a group of fields) in a database table that creates a link between two tables. It is used to maintain referential integrity by ensuring that the value in the foreign key column corresponds to a value in the primary key of another table.

Composite Key
Sometimes, a table might not have a single column/attribute that uniquely identifies all the records of a table. To uniquely identify rows of a table, a combination of two or more columns/attributes can be used.

----------------------------------------------------------------------

ACID properties
ACID properties are a set of principles that ensure database transactions are processed reliably and maintain data integrity.

Atomicity: This property ensures that a transaction is treated as a single, indivisible unit of work. Either all operations within the transaction are completed successfully, or none are applied. If any part of the transaction fails, the entire transaction is rolled back to maintain consistency.

Consistency: This property ensures that a transaction brings the database from one valid state to another valid state, preserving database integrity. It enforces that all data rules and constraints are maintained throughout the transaction.

Isolation: This property ensures that transactions are executed independently of one another. The intermediate state of a transaction is not visible to other transactions until it is completed, preventing conflicts and ensuring that concurrent transactions do not interfere with each other.

Durability: This property ensures that once a transaction is committed, its changes are permanently recorded in the database, even in the event of a system failure. Committed data is not lost or undone.



-----------------------------------------------------------------------

Structured Query Language

Structured Query Language (SQL), as we all know, is the database language by which we can perform certain operations on the existing database, and we can also use this language to create a database. SQL uses certain commands like CREATE, DROP, INSERT, etc. to carry out the required tasks. 
SQL commands are like instructions to a table. It is used to interact with the database with some operations. It is also used to perform specific tasks, functions, and queries of data. SQL can perform various tasks like creating a table, adding data to tables, dropping the table, modifying the table, set permission for users.

*/