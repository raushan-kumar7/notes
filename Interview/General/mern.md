# MERN Stack Interview Guide for TCS Digital Role

## MongoDB (M)

### Key Concepts
- **NoSQL Database**: Document-oriented database storing data in JSON-like documents (BSON)
- **Collections**: Equivalent to tables in relational databases
- **Documents**: Individual records stored as key-value pairs
- **Schema-less**: Flexible structure, no predefined schema required

### Core Features
- **Horizontal Scaling**: Sharding support for large datasets
- **Indexing**: B-tree indexes for fast query performance
- **Aggregation Pipeline**: Powerful data processing framework
- **Replication**: Master-slave architecture for high availability

### Common Interview Questions

**Q1: What are the advantages of MongoDB over SQL databases?**
- Flexible schema design
- Better performance for read-heavy applications
- Native JSON support
- Horizontal scaling capabilities
- Faster development cycles

**Q2: Explain MongoDB indexing**
- Indexes improve query performance
- Types: Single field, Compound, Multikey, Text, Geospatial
- `db.collection.createIndex()` to create indexes
- Use `explain()` to analyze query performance

**Q3: What is aggregation pipeline?**
- Framework for data transformation and analysis
- Stages: `$match`, `$group`, `$project`, `$sort`, `$limit`
- Example: `db.users.aggregate([{$match: {age: {$gte: 18}}}, {$group: {_id: "$city", count: {$sum: 1}}}])`

### Practical Code Examples
```javascript
// Connection
const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/mydb');

// Schema Definition
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
  email: { type: String, unique: true },
  age: Number,
  createdAt: { type: Date, default: Date.now }
});

// CRUD Operations
const User = mongoose.model('User', userSchema);

// Create
const newUser = new User({ name: 'John', email: 'john@example.com' });
await newUser.save();

// Read
const users = await User.find({ age: { $gte: 18 } });

// Update
await User.updateOne({ _id: userId }, { $set: { age: 25 } });

// Delete
await User.deleteOne({ _id: userId });
```

---

## Express.js (E)

### Key Concepts
- **Web Framework**: Fast, minimalist framework for Node.js
- **Middleware**: Functions that execute during request-response cycle
- **Routing**: Handling different HTTP requests and URLs
- **RESTful APIs**: Creating scalable web services

### Core Features
- **Middleware Stack**: Built-in and custom middleware support
- **Template Engines**: Support for EJS, Handlebars, Pug
- **Error Handling**: Centralized error management
- **Static File Serving**: Built-in static file server

### Common Interview Questions

**Q1: What is middleware in Express.js?**
- Functions that have access to request, response, and next middleware
- Execute code, modify req/res objects, end request-response cycle
- Types: Application-level, Router-level, Error-handling, Built-in, Third-party

**Q2: Explain Express.js routing**
- Method to determine how application responds to client requests
- Route methods: GET, POST, PUT, DELETE, PATCH
- Route paths can include strings, patterns, or regular expressions

**Q3: How do you handle errors in Express.js?**
- Error-handling middleware with 4 parameters: (err, req, res, next)
- Must be defined last, after other middleware
- Use try-catch blocks for async operations

### Practical Code Examples
```javascript
const express = require('express');
const app = express();

// Middleware
app.use(express.json()); // Body parser
app.use(express.static('public')); // Static files

// Custom middleware
const logger = (req, res, next) => {
  console.log(`${req.method} ${req.url} - ${new Date().toISOString()}`);
  next();
};
app.use(logger);

// Routes
app.get('/api/users', async (req, res) => {
  try {
    const users = await User.find();
    res.json(users);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

app.post('/api/users', async (req, res) => {
  try {
    const user = new User(req.body);
    await user.save();
    res.status(201).json(user);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

// Error handling middleware
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).json({ error: 'Something went wrong!' });
});

app.listen(3000, () => {
  console.log('Server running on port 3000');
});
```

---

## React.js (R)

### Key Concepts
- **Component-Based**: UI built using reusable components
- **Virtual DOM**: Efficient DOM manipulation and rendering
- **JSX**: JavaScript XML syntax extension
- **State Management**: Managing component data and UI state

### Core Features
- **Hooks**: useState, useEffect, useContext, custom hooks
- **Props**: Data passing between components
- **Event Handling**: Synthetic events for cross-browser compatibility
- **Conditional Rendering**: Dynamic UI based on state/props

### Common Interview Questions

**Q1: What is Virtual DOM and how does it work?**
- JavaScript representation of real DOM
- React creates virtual DOM tree, compares with previous version
- Calculates minimum changes needed (diffing algorithm)
- Updates only changed elements (reconciliation)

**Q2: Explain React Hooks**
- Functions that let you use state and lifecycle features in functional components
- Rules: Only call at top level, only call from React functions
- Common hooks: useState, useEffect, useContext, useReducer

**Q3: What is the difference between state and props?**
- **State**: Internal component data, mutable, managed within component
- **Props**: External data passed from parent, immutable, read-only

### Practical Code Examples
```jsx
import React, { useState, useEffect } from 'react';

// Functional Component with Hooks
const UserList = () => {
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    fetchUsers();
  }, []);

  const fetchUsers = async () => {
    try {
      const response = await fetch('/api/users');
      const data = await response.json();
      setUsers(data);
    } catch (err) {
      setError(err.message);
    } finally {
      setLoading(false);
    }
  };

  const handleDeleteUser = async (userId) => {
    try {
      await fetch(`/api/users/${userId}`, { method: 'DELETE' });
      setUsers(users.filter(user => user._id !== userId));
    } catch (err) {
      setError(err.message);
    }
  };

  if (loading) return <div>Loading...</div>;
  if (error) return <div>Error: {error}</div>;

  return (
    <div>
      <h2>Users</h2>
      {users.map(user => (
        <UserCard 
          key={user._id} 
          user={user} 
          onDelete={() => handleDeleteUser(user._id)}
        />
      ))}
    </div>
  );
};

// Child Component
const UserCard = ({ user, onDelete }) => {
  return (
    <div className="user-card">
      <h3>{user.name}</h3>
      <p>{user.email}</p>
      <button onClick={onDelete}>Delete</button>
    </div>
  );
};

export default UserList;
```

---

## Node.js (N)

### Key Concepts
- **JavaScript Runtime**: Server-side JavaScript execution environment
- **Event-Driven**: Non-blocking, asynchronous I/O operations
- **Single-Threaded**: Uses event loop for concurrency
- **NPM**: Package manager with extensive library ecosystem

### Core Features
- **Modules**: CommonJS and ES6 module systems
- **File System**: Built-in fs module for file operations
- **HTTP Server**: Built-in http module for web servers
- **Streams**: Efficient data handling for large datasets

### Common Interview Questions

**Q1: What is the Event Loop in Node.js?**
- Single-threaded mechanism handling asynchronous operations
- Phases: Timer, Pending callbacks, Poll, Check, Close callbacks
- Enables non-blocking I/O despite single thread

**Q2: Explain the difference between process.nextTick() and setImmediate()**
- **process.nextTick()**: Executes before any other I/O events
- **setImmediate()**: Executes after I/O events in current phase
- nextTick has higher priority than setImmediate

**Q3: What are Streams in Node.js?**
- Objects for handling streaming data
- Types: Readable, Writable, Duplex, Transform
- Memory efficient for large datasets
- Built on EventEmitter pattern

### Practical Code Examples
```javascript
const fs = require('fs');
const path = require('path');
const { promisify } = require('util');

// File operations
const readFileAsync = promisify(fs.readFile);
const writeFileAsync = promisify(fs.writeFile);

// Async/Await example
const processFile = async (filename) => {
  try {
    const data = await readFileAsync(filename, 'utf8');
    const processedData = data.toUpperCase();
    await writeFileAsync('output.txt', processedData);
    console.log('File processed successfully');
  } catch (error) {
    console.error('Error processing file:', error);
  }
};

// Stream example
const processLargeFile = () => {
  const readStream = fs.createReadStream('large-file.txt');
  const writeStream = fs.createWriteStream('output.txt');

  readStream.on('data', (chunk) => {
    const processedChunk = chunk.toString().toUpperCase();
    writeStream.write(processedChunk);
  });

  readStream.on('end', () => {
    writeStream.end();
    console.log('Large file processed');
  });

  readStream.on('error', (error) => {
    console.error('Read error:', error);
  });
};

// Custom module example
class DatabaseConnection {
  constructor(connectionString) {
    this.connectionString = connectionString;
    this.isConnected = false;
  }

  async connect() {
    // Simulate connection
    return new Promise((resolve) => {
      setTimeout(() => {
        this.isConnected = true;
        resolve('Connected to database');
      }, 1000);
    });
  }

  async query(sql) {
    if (!this.isConnected) {
      throw new Error('Database not connected');
    }
    // Simulate query execution
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve(`Query result for: ${sql}`);
      }, 500);
    });
  }
}

module.exports = DatabaseConnection;
```

---

## MERN Stack Integration Example

### Complete Application Structure
```
project/
├── client/          (React frontend)
├── server/          (Express + Node.js backend)
├── models/          (MongoDB schemas)
├── routes/          (API routes)
├── middleware/      (Custom middleware)
└── config/          (Database configuration)
```

### Full Stack Example
```javascript
// Backend: server.js
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const app = express();

// Middleware
app.use(cors());
app.use(express.json());

// Database connection
mongoose.connect('mongodb://localhost:27017/mernapp');

// User Model
const userSchema = new mongoose.Schema({
  name: String,
  email: String,
  age: Number
});
const User = mongoose.model('User', userSchema);

// API Routes
app.get('/api/users', async (req, res) => {
  const users = await User.find();
  res.json(users);
});

app.post('/api/users', async (req, res) => {
  const user = new User(req.body);
  await user.save();
  res.json(user);
});

app.listen(5000, () => console.log('Server running on port 5000'));
```

```jsx
// Frontend: App.js
import React, { useState, useEffect } from 'react';
import axios from 'axios';

function App() {
  const [users, setUsers] = useState([]);
  const [formData, setFormData] = useState({ name: '', email: '', age: '' });

  useEffect(() => {
    fetchUsers();
  }, []);

  const fetchUsers = async () => {
    const response = await axios.get('http://localhost:5000/api/users');
    setUsers(response.data);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    await axios.post('http://localhost:5000/api/users', formData);
    setFormData({ name: '', email: '', age: '' });
    fetchUsers();
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          placeholder="Name"
          value={formData.name}
          onChange={(e) => setFormData({...formData, name: e.target.value})}
        />
        <input
          type="email"
          placeholder="Email"
          value={formData.email}
          onChange={(e) => setFormData({...formData, email: e.target.value})}
        />
        <input
          type="number"
          placeholder="Age"
          value={formData.age}
          onChange={(e) => setFormData({...formData, age: e.target.value})}
        />
        <button type="submit">Add User</button>
      </form>

      <div>
        {users.map(user => (
          <div key={user._id}>
            <h3>{user.name}</h3>
            <p>{user.email} - Age: {user.age}</p>
          </div>
        ))}
      </div>
    </div>
  );
}

export default App;
```

## TCS Interview Tips

1. **Focus on practical examples**: Be ready to explain code you've written
2. **Understand the full request-response cycle**: From React frontend to MongoDB database
3. **Know debugging techniques**: Console logging, error handling, browser dev tools
4. **Be familiar with deployment**: PM2, Docker, cloud platforms
5. **Understand security basics**: Authentication, CORS, input validation
6. **Practice coding problems**: Implement CRUD operations, handle async operations
7. **Know performance optimization**: Code splitting, lazy loading, database indexing

## Common Project Questions
- Explain a MERN project you've built
- How do you handle state management in large React applications?
- What challenges have you faced with MongoDB and how did you solve them?
- How do you ensure API security in Express.js?
- Describe your experience with deployment and DevOps