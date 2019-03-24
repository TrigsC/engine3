/*
 *	engine/util/Observer.cpp generated by engine3 IDL compiler 0.60
 */

#include "Observer.h"

#include "engine/log/Logger.h"

#include "engine/util/Observable.h"

/*
 *	ObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 3437531614,RPC_GETOBJECTID__,RPC_COMPARETO__OBSERVER_,RPC_SETOBSERVERTYPE__INT_,RPC_ISOBSERVERTYPE__INT_};

Observer::Observer() : ManagedObject(DummyConstructorParameter::instance()) {
	ObserverImplementation* _implementation = new ObserverImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Observer");
}

Observer::Observer(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("Observer");
}

Observer::~Observer() {
}



int Observer::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	ObserverImplementation* _implementation = static_cast<ObserverImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
	}
}

unsigned long long Observer::getObjectID() {
	ObserverImplementation* _implementation = static_cast<ObserverImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETOBJECTID__);

		return method.executeWithUnsignedLongReturn();
	} else {
		return _implementation->getObjectID();
	}
}

int Observer::compareTo(Observer* obj) {
	ObserverImplementation* _implementation = static_cast<ObserverImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_COMPARETO__OBSERVER_);
		method.addObjectParameter(obj);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->compareTo(obj);
	}
}

void Observer::setObserverType(unsigned int type) {
	ObserverImplementation* _implementation = static_cast<ObserverImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETOBSERVERTYPE__INT_);
		method.addUnsignedIntParameter(type);

		method.executeWithVoidReturn();
	} else {
		_implementation->setObserverType(type);
	}
}

bool Observer::isObserverType(unsigned int type) const {
	ObserverImplementation* _implementation = static_cast<ObserverImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISOBSERVERTYPE__INT_);
		method.addUnsignedIntParameter(type);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->isObserverType(type);
	}
}

DistributedObjectServant* Observer::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Observer::_getImplementationForRead() const {
	return _impl;
}

void Observer::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ObserverImplementation
 */

ObserverImplementation::ObserverImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


ObserverImplementation::~ObserverImplementation() {
}


void ObserverImplementation::finalize() {
}

void ObserverImplementation::_initializeImplementation() {
	_setClassHelper(ObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Observer*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ObserverImplementation::_getStub() {
	return _this.get();
}

ObserverImplementation::operator const Observer*() {
	return _this.get();
}

void ObserverImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void ObserverImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void ObserverImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void ObserverImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void ObserverImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void ObserverImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void ObserverImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void ObserverImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Observer");

}

void ObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ObserverImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ObserverImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x893f1c9: //Observer.observerType
		TypeInfo<unsigned int >::parseFromBinaryStream(&observerType, stream);
		return true;

	}

	return false;
}

void ObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x893f1c9; //Observer.observerType
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&observerType, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

void ObserverImplementation::writeJSON(nlohmann::json& j) {
	ManagedObjectImplementation::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	thisObject["observerType"] = observerType;

	j["Observer"] = thisObject;
}

int ObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// engine/util/Observer.idl():  		return 1;
	return 1;
}

ObserverImplementation::ObserverImplementation() {
	_initializeImplementation();
	// engine/util/Observer.idl():  		observerType = 0;
	observerType = 0;
}

int ObserverImplementation::compareTo(Observer* obj) {
	// engine/util/Observer.idl():  			return 0;
	if (getObjectID() < obj->getObjectID())	// engine/util/Observer.idl():  			return 1;
	return 1;

	else 	// engine/util/Observer.idl():  			return 0;
	if (getObjectID() > obj->getObjectID())	// engine/util/Observer.idl():  			return -1;
	return -1;

	else 	// engine/util/Observer.idl():  			return 0;
	return 0;
}

void ObserverImplementation::setObserverType(unsigned int type) {
	// engine/util/Observer.idl():  		observerType = type;
	observerType = type;
}

bool ObserverImplementation::isObserverType(unsigned int type) const{
	// engine/util/Observer.idl():  		return observerType == type;
	return observerType == type;
}

/*
 *	ObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ObserverAdapter::ObserverAdapter(Observer* obj) : ManagedObjectAdapter(obj) {
}

void ObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		{
			unsigned int eventType = inv->getUnsignedIntParameter();
			Observable* observable = static_cast<Observable*>(inv->getObjectParameter());
			ManagedObject* arg1 = static_cast<ManagedObject*>(inv->getObjectParameter());
			long long arg2 = inv->getSignedLongParameter();
			
			int _m_res = notifyObserverEvent(eventType, observable, arg1, arg2);
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_GETOBJECTID__:
		{
			
			unsigned long long _m_res = getObjectID();
			resp->insertLong(_m_res);
		}
		break;
	case RPC_COMPARETO__OBSERVER_:
		{
			Observer* obj = static_cast<Observer*>(inv->getObjectParameter());
			
			int _m_res = compareTo(obj);
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_SETOBSERVERTYPE__INT_:
		{
			unsigned int type = inv->getUnsignedIntParameter();
			
			setObserverType(type);
			
		}
		break;
	case RPC_ISOBSERVERTYPE__INT_:
		{
			unsigned int type = inv->getUnsignedIntParameter();
			
			bool _m_res = isObserverType(type);
			resp->insertBoolean(_m_res);
		}
		break;
	default:
		ManagedObjectAdapter::invokeMethod(methid, inv);
	}
}

int ObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return (static_cast<Observer*>(stub))->notifyObserverEvent(eventType, observable, arg1, arg2);
}

unsigned long long ObserverAdapter::getObjectID() {
	return (static_cast<Observer*>(stub))->getObjectID();
}

int ObserverAdapter::compareTo(Observer* obj) {
	return (static_cast<Observer*>(stub))->compareTo(obj);
}

void ObserverAdapter::setObserverType(unsigned int type) {
	(static_cast<Observer*>(stub))->setObserverType(type);
}

bool ObserverAdapter::isObserverType(unsigned int type) const {
	return (static_cast<Observer*>(stub))->isObserverType(type);
}

/*
 *	ObserverHelper
 */

ObserverHelper* ObserverHelper::staticInitializer = ObserverHelper::instance();

ObserverHelper::ObserverHelper() {
	className = "Observer";

	Core::getObjectBroker()->registerClass(className, this);
}

void ObserverHelper::finalizeHelper() {
	ObserverHelper::finalize();
}

DistributedObject* ObserverHelper::instantiateObject() {
	return new Observer(DummyConstructorParameter::instance());
}

DistributedObjectServant* ObserverHelper::instantiateServant() {
	return new ObserverImplementation();
}

DistributedObjectPOD* ObserverHelper::instantiatePOD() {
	return new ObserverPOD();
}

DistributedObjectAdapter* ObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ObserverAdapter(static_cast<Observer*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ObserverPOD
 */

ObserverPOD::~ObserverPOD() {
}

ObserverPOD::ObserverPOD(void) {
	_className = "Observer";
}


void ObserverPOD::writeJSON(nlohmann::json& j) {
	ManagedObjectPOD::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	thisObject["observerType"] = observerType;

	j["Observer"] = thisObject;
}


void ObserverPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ObserverPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ObserverPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x893f1c9; //Observer.observerType
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&observerType, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

bool ObserverPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x893f1c9: //Observer.observerType
		TypeInfo<unsigned int >::parseFromBinaryStream(&observerType, stream);
		return true;

	}

	return false;
}

void ObserverPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ObserverPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void ObserverPOD::writeObjectCompact(ObjectOutputStream* stream) {
	ManagedObjectPOD::writeObjectCompact(stream);

	TypeInfo<unsigned int >::toBinaryStream(&observerType, stream);


}

