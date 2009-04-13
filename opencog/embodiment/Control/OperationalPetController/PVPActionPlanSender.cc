/*
 * opencog/embodiment/Control/MessagingSystem/PVPActionPlanSender.cc
 *
 * Copyright (C) 2007-2008 Welter Luigi
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * Concrete subclass of ActionPlanSender that sends action plans to the PVP
 */

#include "PVPActionPlanSender.h"
#include "StringMessage.h"

using namespace OperationalPetController;
using namespace std;
using namespace opencog;

PVPActionPlanSender::PVPActionPlanSender(const std::string& petId, NetworkElement * ne)
{
    this->petId = petId;
    this->ne = ne;
    this->logPVPMessage = !(config().get_bool("DISABLE_LOG_OF_PVP_MESSAGES"));
}

PVPActionPlanSender::~PVPActionPlanSender()
{
}

bool PVPActionPlanSender::sendActionPlan(const PerceptionActionInterface::ActionPlan& actionPlan)
{
    MessagingSystem::StringMessage msg(ne->getID(), config().get("PROXY_ID"), actionPlan.getPVPmessage(petId));
    if (logPVPMessage) {
        logger().log(Logger::INFO, "PVPActionPlanSender::sendActionPlan():\n%s\n", msg.getPlainTextRepresentation());
    }
    return ne->sendMessage(msg);
}

bool PVPActionPlanSender::sendEmotionalFeelings(const std::string& feelings)
{
    MessagingSystem::StringMessage msg(ne->getID(), config().get("PROXY_ID"), feelings);
    if (logPVPMessage) {
        logger().log(Logger::INFO, "PVPActionPlanSender::sendEmotionalFeelings():\n%s\n", msg.getPlainTextRepresentation());
    }
    return ne->sendMessage(msg);
}