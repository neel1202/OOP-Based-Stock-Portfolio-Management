Stock Portfolio Tracker (C++ | OOP)

A console-based Stock Portfolio Management System developed using C++ and Object-Oriented Programming (OOP) principles.
This application allows users to manage, analyze, and evaluate their stock investments efficiently with features such as sector-wise classification, profit/loss calculation, and file-based data persistence.

Project Overview
In the modern era of personal finance, individuals increasingly manage their own investment portfolios. Manually tracking multiple stocks can be error-prone and inefficient.
The Stock Portfolio Tracker provides a structured, modular, and user-friendly solution to manage stock investments through a console-based interface.
This project also demonstrates strong implementation of core OOP concepts in a real-world financial application.

Objectives
Develop a console-based stock portfolio management system
Apply Object-Oriented Programming concepts effectively
Categorize stocks into different sectors
Compute real-time profit and loss
Store and retrieve portfolio data using file handling
Ensure code modularity, maintainability, and scalability
System Architecture


The system follows a multi-class layered architecture:
Class Design
Stock (Base Class)
Attributes: stockID, name, purchasePrice, quantity
Declares virtual functions for displaying stock details and calculating profit/loss

Derived Classes

TechStock
PharmaStock
EnergyStock
These classes inherit from Stock and represent sector-specific stocks.
Portfolio Class

Manages a collection of stock objects
Handles adding, displaying, searching, saving, and loading stocks
This design follows SOLID principles, particularly the Open–Closed Principle.

OOP Concepts Implemented
Abstraction
Implemented using an abstract base class Stock that exposes essential interfaces.
Encapsulation
Inheritance
Polymorphism
Virtual functions 
Dynamic Binding


Features

Add new stocks by selecting sector type
Display all stocks in the portfolio
Search stocks by ID or name
Calculate profit and loss dynamically
Save portfolio data to a file
Load previously saved portfolio data
Easily extendable for additional stock sectors

Operational Flow
The user interacts with a menu-driven console interface
The user selects an operation such as adding or viewing stocks
The system processes the request using OOP-based logic
Results are displayed on the console
Portfolio data can be saved and retrieved using file handling

Technologies Used
Programming Language: C++
Programming Paradigm: Object-Oriented Programming
Concepts Used: Inheritance, Polymorphism, STL, File Handling
Interface: Console-based
