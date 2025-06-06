/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/Bindings/PageTransitionEventPrototype.h>
#include <LibWeb/HTML/PageTransitionEvent.h>

namespace Web::HTML {

GC_DEFINE_ALLOCATOR(PageTransitionEvent);

GC::Ref<PageTransitionEvent> PageTransitionEvent::create(JS::Realm& realm, FlyString const& event_name, PageTransitionEventInit const& event_init)
{
    return realm.create<PageTransitionEvent>(realm, event_name, event_init);
}

WebIDL::ExceptionOr<GC::Ref<PageTransitionEvent>> PageTransitionEvent::construct_impl(JS::Realm& realm, FlyString const& event_name, PageTransitionEventInit const& event_init)
{
    return create(realm, event_name, event_init);
}

PageTransitionEvent::PageTransitionEvent(JS::Realm& realm, FlyString const& event_name, PageTransitionEventInit const& event_init)
    : DOM::Event(realm, event_name, event_init)
    , m_persisted(event_init.persisted)
{
}

PageTransitionEvent::~PageTransitionEvent() = default;

void PageTransitionEvent::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(PageTransitionEvent);
    Base::initialize(realm);
}

}
