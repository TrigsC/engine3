/*
 *	engine/util/Facade.cpp generated by engine3 IDL compiler 0.60
 */

#include "Facade.h"

/*
 *	FacadeStub
 */

enum {RPC_INITIALIZESESSION__ = 2342040833,RPC_CANCELSESSION__,RPC_CLEARSESSION__};

Facade::Facade() : ManagedObject(DummyConstructorParameter::instance()) {
	FacadeImplementation* _implementation = new FacadeImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Facade");
}

Facade::Facade(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("Facade");
}

Facade::~Facade() {
}



int Facade::initializeSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->initializeSession();
	}
}

int Facade::cancelSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->cancelSession();
	}
}

int Facade::clearSession() {
	FacadeImplementation* _implementation = static_cast<FacadeImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->clearSession();
	}
}

DistributedObjectServant* Facade::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Facade::_getImplementationForRead() const {
	return _impl;
}

void Facade::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	FacadeImplementation
 */

FacadeImplementation::FacadeImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


FacadeImplementation::~FacadeImplementation() {
}


void FacadeImplementation::finalize() {
}

void FacadeImplementation::_initializeImplementation() {
	_setClassHelper(FacadeHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void FacadeImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Facade*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FacadeImplementation::_getStub() {
	return _this.get();
}

FacadeImplementation::operator const Facade*() {
	return _this.get();
}

void FacadeImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void FacadeImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void FacadeImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void FacadeImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void FacadeImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void FacadeImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void FacadeImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void FacadeImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Facade");

}

void FacadeImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(FacadeImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FacadeImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void FacadeImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FacadeImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FacadeImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

void FacadeImplementation::writeJSON(nlohmann::json& j) {
	ManagedObjectImplementation::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
}

FacadeImplementation::FacadeImplementation() {
	_initializeImplementation();
	// engine/util/Facade.idl():  		Logger.setLoggingName("Facade");
	Logger::setLoggingName("Facade");
}

int FacadeImplementation::initializeSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

int FacadeImplementation::cancelSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

int FacadeImplementation::clearSession() {
	// engine/util/Facade.idl():  		return 0;
	return 0;
}

/*
 *	FacadeAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


FacadeAdapter::FacadeAdapter(Facade* obj) : ManagedObjectAdapter(obj) {
}

void FacadeAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZESESSION__:
		{
			
			int _m_res = initializeSession();
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_CANCELSESSION__:
		{
			
			int _m_res = cancelSession();
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_CLEARSESSION__:
		{
			
			int _m_res = clearSession();
			resp->insertSignedInt(_m_res);
		}
		break;
	default:
		ManagedObjectAdapter::invokeMethod(methid, inv);
	}
}

int FacadeAdapter::initializeSession() {
	return (static_cast<Facade*>(stub))->initializeSession();
}

int FacadeAdapter::cancelSession() {
	return (static_cast<Facade*>(stub))->cancelSession();
}

int FacadeAdapter::clearSession() {
	return (static_cast<Facade*>(stub))->clearSession();
}

/*
 *	FacadeHelper
 */

FacadeHelper* FacadeHelper::staticInitializer = FacadeHelper::instance();

FacadeHelper::FacadeHelper() {
	className = "Facade";

	Core::getObjectBroker()->registerClass(className, this);
}

void FacadeHelper::finalizeHelper() {
	FacadeHelper::finalize();
}

DistributedObject* FacadeHelper::instantiateObject() {
	return new Facade(DummyConstructorParameter::instance());
}

DistributedObjectServant* FacadeHelper::instantiateServant() {
	return new FacadeImplementation();
}

DistributedObjectPOD* FacadeHelper::instantiatePOD() {
	return new FacadePOD();
}

DistributedObjectAdapter* FacadeHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FacadeAdapter(static_cast<Facade*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	FacadePOD
 */

FacadePOD::~FacadePOD() {
}

FacadePOD::FacadePOD(void) {
	_className = "Facade";
}


void FacadePOD::writeJSON(nlohmann::json& j) {
	ManagedObjectPOD::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
}


void FacadePOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FacadePOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FacadePOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

bool FacadePOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void FacadePOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(FacadePOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void FacadePOD::writeObjectCompact(ObjectOutputStream* stream) {
	ManagedObjectPOD::writeObjectCompact(stream);


}

