/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#include "Thread.h"

#ifndef PLATFORM_WIN
#include <unistd.h>
#endif

#include <mysql.h>

AtomicInteger Thread::threadCounter;

pthread_once_t Thread::initThread = PTHREAD_ONCE_INIT;

ThreadLocal<Thread> Thread::currentThread;

void Thread::initializeThread(Thread* thread) {
	currentThread.set(thread);
}

void* Thread::executeThread(void* th) {
	Thread* impl = (Thread*) th;

	currentThread.set(impl);

	mysql_thread_init();

	impl->run();

	if (impl->isDetached())
		delete impl;

	mysql_thread_end();

	return NULL;
}

#ifndef PLATFORM_WIN
pid_t Thread::getProcessID() {
	return getpid();
}
#endif

Thread::Thread() {
	pthread_attr_init(&attributes);

	name = "Thread " + String::valueOf(threadCounter.increment());
}

Thread::~Thread() {
	pthread_attr_destroy(&attributes);
}

void Thread::start() {
	pthread_create(&thread, &attributes, executeThread, this);
}

void Thread::cancel() {
	pthread_cancel(thread);
}

void Thread::kill(int signal) {
	pthread_kill(thread, signal);
}

void Thread::join() {
	if (isDetached())
		setJoinable();

	pthread_join(thread, NULL);
}

void Thread::detach() {
	pthread_detach(thread);
}

void Thread::sleep(uint64 millis) {
	#ifndef PLATFORM_WIN
		struct timespec tm, trem;

		tm.tv_sec = (uint32) millis / 1000;
		tm.tv_nsec = (uint32) (millis % 1000) * 1000000;

		nanosleep(&tm, &trem);
	#else
		Sleep(millis);
	#endif
}

void Thread::sleep(uint64 millis, uint64 nanos) {
	#ifndef PLATFORM_WIN
		struct timespec tm, trem;

		if (millis != 0) {
			tm.tv_sec = (uint32) millis / 1000;
			tm.tv_nsec = (uint32) ((millis % 1000) * 1000000 + nanos);
		} else {
			tm.tv_sec = 0;
			tm.tv_nsec = (uint32) nanos;
		}

		nanosleep(&tm, &trem);
	#else
		//TODO find appropriate method for win32
	#endif
}

bool Thread::isDetached() {
	int state;
	pthread_attr_getdetachstate(&attributes, &state);

	return state == PTHREAD_CREATE_DETACHED;
}

Thread* Thread::getCurrentThread() {
	return currentThread.get();
}

void Thread::setDetached() {
	pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_DETACHED);
}

void Thread::setJoinable() {
	pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);
}

void Thread::setSchedulingPolicy(int policy) {
	pthread_attr_setschedpolicy(&attributes, policy);
}
