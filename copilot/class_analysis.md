# Exposed Class Usage Analysis

## Based on Test Usage Frequency:

### **CRITICAL** (Essential for R interface):
- CppSystem (24 uses) - Core system creation
- CppSystemHistory (21 uses) - History analysis
- CppLinearAbxModel (16 uses) - Primary model type
- CppModel (13 uses) - Base model interface

### **NEEDED FOR COMPREHENSIVE TESTING** (Important but not critical):
- CppRawEventList (10 uses) - Event list handling
- CppMap (6 uses) - Data structure access
- CppPatientState (5 uses) - State tracking
- CppPatient (4 uses) - Patient objects
- CppFacility (4 uses) - Facility objects
- CppSampler (3 uses) - MCMC sampling
- CppEvent (3 uses) - Event objects
- CppUnit (3 uses) - Unit objects

### **OTHER** (Rarely used, candidates for conditional compilation):
- CppInsituParams (3 uses) - Parameter objects
- CppTestParamsAbx (2 uses) - Testing parameters
- CppTestParams (2 uses) - Testing parameters
- CppObject (2 uses) - Base object
- CppLogNormalAbxICP (2 uses) - Model parameters
- CppLogNormalModel (1 use) - Alternative model
- CppLogNormalICP (1 use) - Model parameters
- CppLocationState (1 use) - State objects
- CppHistoryLink (1 use) - History navigation
- CppCountLocationState (1 use) - State tracking
- CppAbxPatientState (1 use) - State tracking
- CppAbxLocationState (1 use) - State tracking

### **NOT TESTED** (Candidates for removal or conditional compilation):
From Module-Infect.cpp exposed classes not found in tests:
- infect::Episode
- infect::EpisodeHistory
- infect::FacilityEpisodeHistory
- infect::RawEvent
- infect::SetLocationState
- infect::SystemEpisodeHistory
- infect::UnitEpisodeHistory
- util::IntMap
- util::List
- util::Random