# Unified Modeling Language (UML)

UML is an industry-standard graphical language used for specifying, visualizing, constructing, and documenting the artifacts of software systems. It simplifies the complex process of software design and is widely employed in Object-Oriented Analysis and Design (OOAD) for software projects.

## Why Use UML?

- **Graphical Notation:** UML utilizes graphical notations that are clearer than natural language (which can be imprecise) and code (which can be too detailed).

- **Overall View:** Helps in acquiring an overall view of a system, making it easier to understand and communicate various aspects.

- **Language and Technology Independence:** UML is not dependent on any specific programming language or technology, making it versatile and widely applicable.

- **Standardization:** UML promotes standardization in software design, moving from fragmentation to a unified approach.

## Uses for UML

- **Sketching:** Utilized as a sketch to communicate aspects of a system, often done on whiteboards or paper to quickly convey ideas.

- **Forward Design:** Used in the early stages of software development, doing UML before actual coding to plan and design the system.

- **Backward Design:** Employed after coding as documentation to capture the design decisions and structure of the implemented system.

- **Blueprint:** Can serve as a complete design blueprint for a system that needs to be implemented.

- **CASE Tools:** Often used with Computer-Aided Software Engineering (CASE) tools for more formal and detailed modeling.

- **Programming Language:** With the right tools, code can be auto-generated and executed from UML, offering an alternative way to implement software.

**Note:** Using UML as a programming language is practical if it significantly speeds up the development process compared to coding directly in a traditional programming language.

## Types of UML Diagrams

Unified Modeling Language (UML) encompasses various diagram types that serve different purposes throughout the software development life cycle. Here's a subset of UML diagrams that are widely used:

## 1. Use Case Diagram

- **Purpose:** Describes the interactions between users (actors) and a system to showcase the system's functionality from a user's perspective.
- **Elements:** Actors, Use Cases, Relationships.

## 2. Class Diagram

- **Purpose:** Represents the static structure of a system, showcasing classes, their attributes, methods, and relationships.
- **Elements:** Classes, Attributes, Methods, Relationships.

## 3. Sequence Diagram

- **Purpose:** Illustrates the interactions between objects over time, emphasizing the sequence of messages exchanged between them.
- **Elements:** Lifelines, Messages, Activation Bars.

## 4. Collaboration or Communication Diagram

- **Purpose:** Similar to Sequence Diagram, emphasizes the relationships between objects but from a different perspective.
- **Elements:** Objects, Links, Messages.

## 5. State Diagram

- **Purpose:** Describes the various states an object can be in and transitions between those states based on events.
- **Elements:** States, Transitions, Events.

## 6. Activity Diagram

- **Purpose:** Represents the flow of activities within a system, showcasing the dynamic aspects of a process.
- **Elements:** Actions, Decision Nodes, Flow Control Elements.

**Note:** These diagrams are a subset of the various UML diagrams available, each serving a specific purpose in visualizing different aspects of a software system during its development life cycle.

## Use-Case Diagrams

A Use-Case Diagram is a type of diagram in Unified Modeling Language (UML) that represents a set of use cases, providing a high-level view of the interactions between external users (actors) and the software system.

## Components of a Use-Case Diagram

### Actors

- **Definition:** A role played by a user or an external system concerning the system under consideration.
- **Example:** Human users, inanimate physical objects (e.g., a robot), external systems requiring information.

### Use Case

- **Definition:** A set of scenarios describing an interaction between a user (actor) and the system, capturing user requirements.
- **Example:** A specific functionality or feature that the system provides to its users.

### System Boundary

- **Representation:** A rectangle that delineates the boundary between actors and the system.
- **Purpose:** Clearly defines what is inside the system and what is external to it.

## Purpose of Use-Case Diagrams

- **Modeling Interaction:** Illustrates the interactions between external users and the system.
- **User Scenarios:** Captures user requirements through various scenarios.
- **Contract:** Serves as a contract between end users and software developers, providing a shared understanding of system functionality.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/c1a3a392-22be-4f6e-872c-f96a0fa6209a)

## Use-Case Diagram Relationships

## Association

- **Representation:** Solid line connecting an actor and a use case.
- **Purpose:** Illustrates communication between an actor and a use case.
- **Example:** A customer (actor) associating with the "Place Order" use case.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/bf0a91f5-48d3-4b10-af4f-61507a5e87c9)

## Generalization

- **Representation:** Line with a triangular arrowhead pointing toward the parent use case.
- **Purpose:** Represents a relationship between a general use case and a specialized use case.
- **Example:** A general use case "Manage Account" being specialized by "Create Account" and "Update Account."

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/15a2d0ee-17c4-4af3-ba1e-9c15332b80d4)

## Include

- **Representation:** Dotted line labeled <<include>>, starting at the base use case and ending with an arrow pointing to the include use case.
- **Purpose:** Indicates that a chunk of behavior is similar across multiple use cases.
- **Usage:** Instead of duplicating the description of behavior, use "include."
- **Example:** "Login" use case including "Authentication" behavior.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/dbca7fc8-f3ee-4afe-93f1-35c28ebdd239)

## Extend

- **Representation:** Dotted line labeled <<extend>> with an arrow toward the base case.
- **Purpose:** Signifies that the extending use case may add behavior to the base use case.
- **Usage:** The base class declares "extension points" for possible extensions.
- **Example:** "Make Payment" use case extending "Place Order" for additional payment methods.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/7660c603-c80c-46ee-af51-ddb29b6bc823)

## Example:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/edc0b934-d967-4a1a-bb89-454f1e030e45)

- Both Make Appointment and Request Medication include Check Patient Record as a subtask (include)
- The extension point is written inside the base case Pay bill; the extending class Defer payment adds the behavior of this extension point. (extend)
- Pay Bill is a parent use case and Bill Insurance is the child use case. (generalization)


## Class diagram
-  A class diagram depicts classes and their interrelationships
- Used for describing structure and behavior in the use cases
- Provide a conceptual model of the system in terms of entities and their relationships
- Used for requirement capture, end-user interaction
- Detailed class diagrams are used for developers
- Each class is represented by a rectangle subdivided into three compartments
  - Name
  - Attributes
  - Operations
- Modifiers are used to indicate the visibility of attributes and operations.
  - ‘+’ is used to denote Public visibility (everyone)
  - ‘#’ is used to denote Protected visibility (friends and derived)
  - ‘-’ is used to denote Private visibility (no one)
- By default, attributes are hidden and operations are visible.

## Class attributes
- attributes (fields, instance variables)
  - visibility name: type [count] = default_value
  - visibility: <br />'+' public
                <br />'#' protected
                <br />'-' private
                <br />'~' package (default)
                <br />'/' derived
- underline <ins> static attributes </ins>
- **derived attribute**: not stored, but can be computed from other attribute values
- attribute example:<br />
`- balance : double = 0.00`
<br />

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/0932e3f8-208c-44c1-bc17-ced0bfcd20fb)

## Diagram of one class
- class name in top of box
  - write <<interface>> on top of interfaces' names
  - use italics for an abstract class name
- attributes (optional)
  - should include all fields of the object
- operations / methods (optional)
  - may omit trivial (get/set) methods
  -should not include inherited methods

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/23716f04-8a29-46b1-858d-0e112de8553f)
